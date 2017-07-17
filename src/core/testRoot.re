external typeSystemData : array SharedTypes.typeItem = "data" [@@bs.val];

ReactDOMRe.renderToElementWithId
  <TypeSystem data=typeSystemData /> "ts-explorer";
