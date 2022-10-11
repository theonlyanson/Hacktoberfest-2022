import React, { useState } from "react";
import PropTypes from "prop-types";
import { Link, NavLink } from "react-router-dom";
export default function Navbar(props) {
  const [show, setShow] = useState(false);

  return (
    <nav
      className={`navbar navbar-expand-lg navbar-${props.mode} bg-${props.mode}`}
    >
      <div className="container-fluid">
        <NavLink className="navbar-brand" to="/">
          {props.title}
        </NavLink>
        <button
          className="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="/navbarSupportedContent"
          aria-controls="navbarSupportedContent"
          aria-expanded="false"
          aria-label="Toggle navigation"
          onClick={() => setShow(!show)}
        >
          <span className="navbar-toggler-icon"></span>
        </button>
        <div className={`collapse navbar-collapse ${show ? "show" : ""} `}>
          <ul className="navbar-nav me-auto mb-2 mb-lg-0">
            <li className="nav-item">
              <NavLink
                className="nav-link"
                id="nav-links"
                aria-current="page"
                to="/"
                activeClassName="activelink"
              >
                Home
              </NavLink>
            </li>
            <li className="nav-item">
              <NavLink className="nav-link" activeClassName="nav-active" id="nav-links" to="/about">
                About
              </NavLink>
            </li>
          </ul>

          <div
            className={`form-check form-switch text-${
              props.mode === "light" ? "dark" : "light"
            }`}
          >
            <input
              className="form-check-input"
              type="checkbox"
              id="flexSwitchCheckChecked"
              onClick={props.toggleMode}
            />
            <label
              className="form-check-label"
              htmlFor="flexSwitchCheckChecked"
            >
              {props.mode}
            </label>
          </div>
        </div>
      </div>
    </nav>
  );
}
Navbar.propTypes = { title: PropTypes.isRequired };
Navbar.defaultProps = { title: "Your title here" };
