import gulp from 'gulp';
import ghPages from 'gh-pages';
import path from 'path';

gulp.task('publish.copy.resources', () => {
    gulp.src('src/core/css/main.css').pipe(gulp.dest('ghPages'));
    gulp.src('node_modules/bootstrap/dist/css/bootstrap.min.css').pipe(gulp.dest('ghPages'));
    gulp.src('bundledOutputs/testSystem.js').pipe(gulp.dest('ghPages'));
    gulp.src('bundledOutputs/fonts/**').pipe(gulp.dest('ghPages/fonts'));
});

gulp.task('publish', ['publish.copy.resources'], () => {
    ghPages.publish(path.join(__dirname, '../../ghPages'));
});