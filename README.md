### Overview

This plugin parses type system of XebiaLabs products. 
Here is a couple of examples for 2 products: XL Deploy and XL Release.

### Configuration

#### Prerequisites

#### To be able to compile it
* ocaml

#### To be able to have a proper syntax highlight, and code formatting.
* [ocamlmerlin](https://github.com/ocaml/merlin)
* [reason tools](https://reasonml.github.io/guide/tools/#refmt)

#### Clone project and compile it
```
git clone git@github.com:acierto/ts-explorer.git
cd ts-explorer
npm install
npm start
# in another tab
npm run build
```

After you see the webpack compilation succeed (the `npm run build` step), 
open up the nested html files in `src/*` (**no server needed!**). 
Then modify whichever file in `src` and refresh the page to see the changes.

There are 2 pages to view: *xld-index.html* and *xlr-index.html*.

### Demo

[XLD Type System](https://acierto.github.io/ts-explorer/xld-index.html)

[XLR Type System](https://acierto.github.io/ts-explorer/xlr-index.html)