import gulp from 'gulp';
import runSequence from 'run-sequence';

gulp.task('release-it', (cb) => runSequence('webpack-prod', 'bump-release', cb));

gulp.task('default', (cb) => runSequence('watch', cb));
