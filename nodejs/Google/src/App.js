import "./App.css";
import Navbar from "./components/Navbar";
import TextForm from "./components/TextForm";
import About from "./components/About";
import React, { useState, Fragment } from "react";
import Alert from "./components/Alert";
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";

function App() {
  const [mode, setMode] = useState("light"); //whether dark mode is enabled or not...default
  const [alert, setAlert] = useState(null);

  const showAlert = (message, type) => {
    setAlert({
      msg: message,
      type: type,
    });
    setTimeout(() => {
      setAlert(null);
    }, 2500);
  };

  const toggleMode = () => {
    if (mode === "light") {
      setMode("dark");
      document.body.style.backgroundColor = "#042743";

      showAlert("Dark Mode has been enabled", "success");
    } else {
      setMode("light");
      document.body.style.backgroundColor = "white";
      showAlert("Light Mode has been enabled", "success");
    }
  };

  return (
    <>
      <Router>
        <Navbar title="TextUtils" mode={mode} toggleMode={toggleMode} />
        <Alert alert={alert} />
        <div className="container">
          <Routes>
            <Route
              path="/"
              element={
                <TextForm
                  showAlert={showAlert}
                  heading="Enter the text to analyze"
                  mode={mode}
                />
              }
            ></Route>
            <Route path="/about" element={<About />}></Route>
          </Routes>
        </div>
      </Router>
    </>
  );
}

export default App;
