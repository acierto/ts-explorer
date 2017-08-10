import gulp from 'gulp';
import webpack from 'webpack';
import webpackStream from 'webpack-stream';
import plumber from 'gulp-plumber';
import webpackConfig from './webpack.config';

gulp.task('webpack', () => {
        gulp
            .src(['./lib/js/src/core/typeSystemRoot.js', './lib/js/src/core/testRoot.js'])
            .pipe(plumber())
            .pipe(webpackStream(webpackConfig, webpack))
            .pipe(gulp.dest('bundledOutputs'));
    }
);
