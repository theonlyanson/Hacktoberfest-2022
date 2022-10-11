import DiscordIcon from "../DiscordIcon";
import { ReactComponent as Twitter } from "../../assets/twitter_icon.svg";
import { ReactComponent as Instagram } from "../../assets/instagram_icon.svg";
import { ReactComponent as Facebook } from "../../assets/facebook_icon.svg";
import { ReactComponent as Youtube } from "../../assets/youtube_icon.svg";
import classes from "./footer.module.css";
import { useHistory } from "react-router-dom";

const Footer = () => {
    const history = useHistory();

    const registerHandler = () => {
        history.push("/register");
    };

    return (
        <footer className={classes.footer}>
            <div className={classes.gridContainer}>
                <div className={classes.footermain}>
                    <h1>IMAGINE A PLACE</h1>
                    <select title="language">
                        <option>English,USA</option>
                        <option>Hindi,India</option>
                        <option>French,France</option>
                    </select>
                    <div className={classes.mediaIcons}>
                        <Twitter />
                        <Instagram />
                        <Facebook />
                        <Youtube />
                    </div>
                </div>
                <div className={classes.product}>
                    <p>Product</p>
                    <ul>
                        <li>
                            <a href="/welcome">Download</a>
                        </li>
                        <li>
                            <a href="/welcome">Nitro</a>
                        </li>
                        <li>
                            <a href="/welcome">Status</a>
                        </li>
                    </ul>
                </div>
                <div className={classes.company}>
                    <p>Company</p>
                    <ul>
                        <li>
                            <a href="/welcome">About</a>
                        </li>
                        <li>
                            <a href="/welcome">Jobs</a>
                        </li>
                        <li>
                            <a href="/welcome">Branding</a>
                        </li>
                        <li>
                            <a href="/welcome">Newsroom</a>
                        </li>
                    </ul>
                </div>
                <div className={classes.resources}>
                    <p>Resources</p>
                    <ul>
                        <li>
                            <a href="/welcome">College</a>
                        </li>
                        <li>
                            <a href="/welcome">Support</a>
                        </li>
                        <li>
                            <a href="/welcome">Safety</a>
                        </li>
                        <li>
                            <a href="/welcome">Blog</a>
                        </li>
                        <li>
                            <a href="/welcome">Feedback</a>
                        </li>
                        <li>
                            <a href="/welcome">Developers</a>
                        </li>
                        <li>
                            <a href="/welcome">StreamKit</a>
                        </li>
                    </ul>
                </div>
                <div className={classes.policies}>
                    <p>Policies</p>
                    <ul>
                        <li>
                            <a href="/welcome">Terms</a>
                        </li>
                        <li>
                            <a href="/welcome">Privacy</a>
                        </li>
                        <li>
                            <a href="/welcome">Cookie Settings</a>
                        </li>
                        <li>
                            <a href="/welcome">Guidelines</a>
                        </li>
                        <li>
                            <a href="/welcome">Acknowledgements</a>
                        </li>
                        <li>
                            <a href="/welcome">Licenses</a>
                        </li>
                        <li>
                            <a href="/welcome">Moderation</a>
                        </li>
                    </ul>
                </div>
            </div>
            <div className={classes.footerNav}>
                <DiscordIcon color="#23272a" />
                <button type="button" onClick={registerHandler}>
                    Sign up
                </button>
            </div>
        </footer>
    );
};
export default Footer;
