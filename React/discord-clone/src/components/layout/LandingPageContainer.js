import classes from "./landingPageContainer.module.css";

const LandingPageContainer = (props) => {
    return (
        <div
            className={`${classes.container} ${
                props.isReversed && classes.reversed
            }`}
        >
            {props.children}
        </div>
    );
};

export default LandingPageContainer;
