open Glamor;

let component = ReasonReact.statelessComponent "PanelTitle";

let titleStyles =
  css [
    display "inline-block",
    fontWeight "bold",
    lineHeight "30px",
    textAlign "center",
    width "auto"
  ];

let make ::text _children => {
  ...component,
  render: fun _ =>
    <div className=titleStyles> (ReasonReact.stringToElement text) </div>
};
