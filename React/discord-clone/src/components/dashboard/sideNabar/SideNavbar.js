import classes from "./sideNavbar.module.css";

const SideNavbar = () => {
    const servers = [
        {
            id: 0,
            serverName: "Server 1",
            serverIcon:
                "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ3eVdzririT7taihU-3jSc0czzGRiD2cyyhg&usqp=CAU",
        },
        {
            id: 1,
            serverName: "Server 2",
            serverIcon:
                "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ_ywjBuR0aplEg869d2Xg7JsEXvmnN--rMZg&usqp=CAU",
        },
    ];

    return (
        <div className={classes.container}>
            <div className={`${classes.icon} ${classes.discordIcon}`}></div>
            <hr color="#36393f" />
            {servers.map((server) => {
                return (
                    <div className={classes.icon} key={server.id}>
                        <img src={server.serverIcon} alt="" />
                        <div className={classes.serverName}>
                            <p>{server.serverName}</p>
                        </div>
                    </div>
                );
            })}
            <div className={`${classes.icon} ${classes.addServerIcon}`}></div>
            <div
                className={`${classes.icon} ${classes.exploreServerIcon}`}
            ></div>
            <div
                className={`${classes.icon} ${classes.downloadAppsIcon}`}
            ></div>
        </div>
    );
};

export default SideNavbar;
