import classes from "./dashboard.module.css";
import SideNavbar from "./sideNabar/SideNavbar";

const Dashboard = () => {
    return (
        <div className={classes.parentContainer}>
            <div className={classes.sideNavbar}>
                <SideNavbar />
            </div>
            <div className={classes.childContainer}>
                <div className={classes.topNavbar}>
                    <div></div>
                    <nav></nav>
                </div>
                <div className={classes.contentContainer}>
                    <div className={classes.container1}></div>
                    <div className={classes.container2}></div>
                    <div className={classes.container3}></div>
                </div>
            </div>
        </div>
    );
};

export default Dashboard;
