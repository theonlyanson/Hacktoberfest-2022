import { Fragment } from "react";
import Details from "./Details";
import Hero from "./Hero";
import Footer from "./Footer";
import classes from "./landingPage.module.css";
import { HiOutlineDownload } from "react-icons/hi";
import { ReactComponent as InviteOnly } from "../../assets/landing_page/invite_only_landing.svg";
import { ReactComponent as HangingOut } from "../../assets/landing_page/hanging_out_easy_landing.svg";
import { ReactComponent as FanDom } from "../../assets/landing_page/fandom_landing.svg";
import { default as JustChilling } from "../../assets/landing_page/just_chiling_landing.svg";

const details = [
    {
        id: 0,
        svg: InviteOnly,
        heading: "Create an invite-only place where you belong",
        text: "Discord servers are organized into topic-based channels where you can collaborate, share, and just talk about your day without clogging up a group chat.",
        isReversed: false,
    },
    {
        id: 1,
        svg: HangingOut,
        heading: "Where hanging out is easy",
        text: "Grab a seat in a voice channel when you're free. Friends in your server can see you're around and instantly pop in to talk without having to call.",
        isReversed: true,
    },
    {
        id: 2,
        svg: FanDom,
        heading: "From few to a fandom",
        text: "Get any community running with moderation tools and custom member access. Give members special powers, set up private channels, and more.",
        isReversed: false,
    },
];

const LandingPage = () => {
    return (
        <Fragment>
            <Hero />
            <main>
                {details.map((item) => {
                    return (
                        <Details
                            svg={item.svg}
                            key={item.id}
                            heading={item.heading}
                            text={item.text}
                            isReversed={item.isReversed}
                        ></Details>
                    );
                })}
                <div className={classes.justChillingContainer}>
                    <div className={classes.justChilling}>
                        <h1>RELIABLE TECH FOR STAYING CLOSE</h1>
                        <p className={classes.justChillingText}>
                            Low-latency voice and video feels like you’re in the
                            same room. Wave hello over video, watch friends
                            stream their games, or gather up and have a drawing
                            session with screen share.
                        </p>

                        <img
                            src={JustChilling}
                            alt="img of how to chill in discord"
                        />
                        <h2>Ready to start your journey?</h2>
                        <button type="button" className={classes.download}>
                            <HiOutlineDownload size="25px" />
                            <p>Download for Windows</p>
                        </button>
                    </div>
                </div>
            </main>
            <Footer />
        </Fragment>
    );
};

export default LandingPage;
