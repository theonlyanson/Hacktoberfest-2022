import DiscordIcon from "../DiscordIcon";
import classes from "./Navbar.module.css";
import { BiMenu } from "react-icons/bi";
import { useHistory } from "react-router-dom";

const Navbar = () => {
    const history = useHistory();

    const loginHandler = () => {
        history.push("/login");
    };

    return (
        <div className={classes.navbar}>
            <nav>
                <DiscordIcon color="#404eed" />
                <ul>
                    <li>
                        <a href="/welcome">Download</a>
                    </li>
                    <li>
                        <a href="/welcome">Nitro</a>
                    </li>
                    <li>
                        <a href="/welcome">Discover</a>
                    </li>
                    <li>
                        <a href="/welcome">Safety</a>
                    </li>
                    <li>
                        <a href="/welcome">Support</a>
                    </li>
                    <li>
                        <a href="/welcome">Blog</a>
                    </li>
                    <li>
                        <a href="/welcome">Careers</a>
                    </li>
                </ul>
                <div className={classes.buttons}>
                    <button type="button" onClick={loginHandler}>
                        Login
                    </button>
                    <BiMenu className={classes.menuIcon} />
                </div>
            </nav>
        </div>
    );
};

export default Navbar;
