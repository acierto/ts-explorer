let contains s1 s2 => {
  let compare s1 s2 => {
    let len = String.length s2;
    for i in 0 to (String.length s1 - len) {
      if (String.sub s1 i len == s2) {
        raise Exit
      }
    };
    raise Not_found
  };
  try (compare s1 s2) {
  | Exit => true
  | Not_found => false
  }
};

let capitalize str => {
  let lowerCaseStr = String.lowercase str;
  let lengthOfStr = String.length str;
  let indexOfEndOfWord = String.sub str 1 (lengthOfStr - 1);
  let capitalizedInitialLetter =
    String.uppercase @@ String.make 1 lowerCaseStr.[0];
  capitalizedInitialLetter ^ indexOfEndOfWord
};
