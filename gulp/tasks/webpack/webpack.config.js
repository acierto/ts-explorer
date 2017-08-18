import R from 'ramda';
import HtmlWebpackPlugin from 'html-webpack-plugin';
const path = require('path');

export const createConfig = (entry, outputFolder, htmlTemplateConfigs = []) =>
    module.exports = {
        entry,
        output: {
            path: path.join(__dirname, outputFolder),
            filename: '[name]-[hash].js',
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
        },
        plugins: R.map((htmlTemplateConfig) => new HtmlWebpackPlugin(htmlTemplateConfig), htmlTemplateConfigs)
    };