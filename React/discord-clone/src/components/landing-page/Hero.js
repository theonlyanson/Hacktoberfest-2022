import Navbar from "./Navbar";
import classes from "./hero.module.css";
import { HiOutlineDownload } from "react-icons/hi";
import { ReactComponent as Leftbg } from "../../assets/landing_page/left_bg_landing_header.svg";
import { Link } from "react-router-dom";

const Hero = () => {
    return (
        <div className={classes.hero}>
            <Navbar />
            <div className={classes.info}>
                <h1>IMAGINE A PLACE...</h1>
                <p>
                    ...where you can belong to a school club, a gaming group, or
                    a worldwide art community. Where just you and a handful of
                    friends can spend time together. A place that makes it easy
                    to talk every day and hang out more often.
                </p>
                <div className={classes.buttons}>
                    <button type="button" className={classes.download}>
                        <HiOutlineDownload size="25px" />
                        <h3>Download for Windows</h3>
                    </button>
                    <Link to="/dashboard">
                        <button type="button" className={classes.openInBrowser}>
                            <h3>Open Discord in your browser</h3>
                        </button>
                    </Link>
                </div>
            </div>
            <Leftbg className={classes.leftbg} />
        </div>
    );
};

export default Hero;
