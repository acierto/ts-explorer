import gulp from 'gulp';
import webpack from 'webpack';
import webpackStream from 'webpack-stream';
import plumber from 'gulp-plumber';
import webpackConfig from './webpack.config';

gulp.task('webpack', () => gulp
    .src(['./src/core/index.js', './lib/js/src/core/typeSystemRoot.js'])
    .pipe(plumber())
    .pipe(webpackStream(webpackConfig, webpack))
    .pipe(gulp.dest('bundledOutputs'))
);
