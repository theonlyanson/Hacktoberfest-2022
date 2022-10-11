import React, { useState } from "react";
export default function TextForm(props) {
  const handleUpClick = () => {
    console.log("up button was clicked" + text);
    let newText = text.toUpperCase();
    setText(newText);
    props.showAlert("Converted to Uppercase", "success");
  };
  const handleLoClick = () => {
    console.log("low button was clicked" + text);
    let newText = text.toLowerCase();
    setText(newText);
    props.showAlert("Converted to Lowercase", "success");
  };
  const handleOnChange = (event) => {
    console.log("ON changed");
    setText(event.target.value);
  };
  const [text, setText] = useState("");
  return (
    <>
      <div
        className="container"
        style={{ color: props.mode === "dark" ? "white" : "#042743" }}
      >
        <h1>{props.heading}</h1>
        <div className="mb-3">
          <textarea
            className="form-control"
            id="myBox  "
            value={text}
            onChange={handleOnChange}
            rows="8"
            style={{
              backgroundColor: props.mode === "dark" ? "grey" : "white",
              color: props.mode === "dark" ? "white" : "#042743",
            }}
          ></textarea>
        </div>
        <button
          className="btn btn-primary mx-1"
          onClick={handleUpClick}
          disabled={text.length === 0}
        >
          Convert to uppercase
        </button>
        <button
          className="btn btn-success mx-1 my-1"
          onClick={handleLoClick}
          disabled={text.length === 0}
        >
          Convert to lowercase
        </button>
      </div>
      <div
        className="container my-3"
        style={{ color: props.mode === "dark" ? "white" : "#042743" }}
      >
        <h1>Your text summary</h1>
        <p>
          {
            text.split(/\s+/).filter((element) => {
              return element.length !== 0;
            }).length
          }{" "}
          words, {text.length} characters
        </p>
        <p>{0.008 * text.split(" ").length} minutes to read!</p>
        <h2>Preview</h2>
        <p>{text.length > 0 ? text : "'Enter something to preview'"}</p>
      </div>

    </>
  );
}
