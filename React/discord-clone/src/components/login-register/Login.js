import classes from "./login.module.css";
import DiscordIcon from "../DiscordIcon";
import { Link } from "react-router-dom";

const Login = () => {
    return (
        <div className={classes.loginParentContainer}>
            <div>
                <div className={classes.loginChildContainer}>
                    <div className={classes.icon}>
                        <DiscordIcon />
                    </div>
                    <div className={classes.welcomeMessage}>
                        <h2>Welcome back!</h2>
                        <p>We're so excited to see you again!</p>
                    </div>
                    <form>
                        <label>Email or phone number</label>
                        <input type="text" required></input>
                        <label>password</label>
                        <input type="password" required></input>
                        <p className={classes.forgotPass}>
                            Forgot your password?
                        </p>
                        <button type="submit">Log In</button>
                        <Link to="/register">
                            <p>
                                Need an account? <span>Register</span>
                            </p>
                        </Link>
                    </form>
                </div>
                <div className={classes.qrcode}>
                    <div className={classes.qrcodeImg}>
                        <img
                            src={require("../../assets/qr_code_inside.png")}
                            alt="qr code"
                        />
                    </div>
                    <h2>Log in with QR Code</h2>
                    <p>
                        Scan this with the <strong>Discord mobile app </strong>
                        to log in instantly.
                    </p>
                </div>
            </div>
        </div>
    );
};

export default Login;
