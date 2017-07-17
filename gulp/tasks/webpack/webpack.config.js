const path = require('path');

module.exports = {
    entry: {
        typeSystem: ['./src/core/index.js', './lib/js/src/core/typeSystemRoot.js'],
        testSystem: ['./src/core/index.js', './lib/js/src/core/testRoot.js']
    },
    output: {
        path: path.join(__dirname, "bundledOutputs"),
        filename: '[name].js',
    },
    module: {
        rules: [
            {
                exclude: /(node_modules)/,
                loader: 'babel-loader',
                options: {
                    cacheDirectory: true
                },
                test: /\.js?$/
            },
            {loader: 'html-loader', test: /\.html$/}, {
                test: /\.css$/,
                use: [
                    'style-loader',
                    'css-loader'
                ]
            },
            {loader: 'file-loader?name=fonts/[name].[ext]', test: /\.(ttf|eot|woff)\??.*$/},
            {
                test: /\.(jpe?g|png|gif|svg|ico)\??.*$/i,
                use: [
                    'file-loader?hash=sha512&digest=hex&name=images/[name]-[hash].[ext]',
                    {
                        loader: 'image-webpack-loader?bypassOnDebug',
                        options: {
                            gifsicle: {interlaced: false},
                            optipng: {optimizationLevel: 7}
                        }
                    }
                ]
            }]
    }
};
