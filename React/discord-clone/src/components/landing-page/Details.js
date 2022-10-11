import LandingPageContainer from "../layout/LandingPageContainer";
import classes from "./details.module.css";

const Details = (props) => {
    const Svg = props.svg;
    return (
        <LandingPageContainer isReversed={props.isReversed}>
            <div
                className={`${props.isReversed && classes.reversed} ${
                    classes.detailsContainer
                }`}
            >
                <div className={classes.svg}>
                    <Svg />
                </div>
                <div className={classes.details}>
                    <h1>{props.heading}</h1>
                    <p>{props.text}</p>
                </div>
            </div>
        </LandingPageContainer>
    );
};

export default Details;
