const path = require('path');

module.exports = {
  entry: {
    typeSystem: './lib/js/src/core/typeSystemRoot.js'
  },
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
