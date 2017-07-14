open Bs_fetch;

external parseJson : Js_json.t => array SharedTypes.typeItem =
  "Object.create" [@@bs.val];

let data =
  Js.Promise.(
    fetch "/deployit/metadata/type" |> then_ Response.json |>
    then_ (
      fun typeSystemData => {
        let data = parseJson typeSystemData;
        ReactDOMRe.renderToElementWithId <TypeSystem data /> "index" |> resolve
      }
    )
  );
