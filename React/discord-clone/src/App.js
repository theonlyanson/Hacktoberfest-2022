import "./App.css";
import LandingPage from "./components/landing-page/LandingPage";
import { Route, Switch, Redirect } from "react-router-dom";
import Login from "./components/login-register/Login";
import Register from "./components/login-register/Register";
import Dashboard from "./components/dashboard/Dashboard";

function App() {
    return (
        <div className="App">
            <Switch>
                <Route path="/" exact>
                    <Redirect to="/welcome" />
                </Route>
                <Route path="/welcome">
                    <LandingPage />
                </Route>
                <Route path="/login">
                    <Login />
                </Route>
                <Route path="/register">
                    <Register />
                </Route>
                <Route path="/dashboard">
                    <Dashboard />
                </Route>
            </Switch>
        </div>
    );
}

export default App;
