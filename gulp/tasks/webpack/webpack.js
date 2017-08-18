import del from 'del';
import gulp from 'gulp';
import webpack from 'webpack';
import webpackStream from 'webpack-stream';
import plumber from 'gulp-plumber';
import {createConfig} from './webpack.config';
import runSequence from 'run-sequence';

gulp.task('clean', () => {
    del.sync(['bundledOutputs', 'ghPages/index.html', 'ghPages/testSystem*.js']);
});

gulp.task('webpack-prod', ['clean'], () => {
        const entry = {
            typeSystem: ['./src/core/index.js', './lib/js/src/core/typeSystemRoot.js']
        };
        const htmlTemplateConfig = [{template: './src/templates/xld-ts-explorer-template.html'}];
        gulp
            .src(['./lib/js/src/core/typeSystemRoot.js'])
            .pipe(plumber())
            .pipe(webpackStream(createConfig(entry, 'bundledOutputs', htmlTemplateConfig), webpack))
            .pipe(gulp.dest('bundledOutputs'));
    }
);

gulp.task('webpack-dev', ['clean'], () => {
        const entry = {
            testSystem: ['./src/core/index.js', './lib/js/src/core/testRoot.js']
        };
        const htmlTemplateConfig = [
            {filename: 'xld-template.html', template: './src/templates/xld-template.html'},
            {filename: 'xlr-template.html', template: './src/templates/xlr-template.html'}
        ];
        gulp
            .src(['./lib/js/src/core/testRoot.js'])
            .pipe(plumber())
            .pipe(webpackStream(createConfig(entry, 'ghPages', htmlTemplateConfig), webpack))
            .pipe(gulp.dest('ghPages'));
    }
);

gulp.task('webpack', (cb) => runSequence('webpack-prod', 'webpack-dev', cb));

