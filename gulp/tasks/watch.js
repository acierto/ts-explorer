import gulp from 'gulp';

gulp.task('watch', () => {
    gulp.watch('src/**/*.re', ['webpack']);
});
