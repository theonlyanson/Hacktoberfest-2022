// only to display things
import headImg from './Trollface.png';
function Header() {
    return (
        <div id="title">
            <img src={headImg} id="titleImg"/>
            <p id="titleText">This is a Meme Generator</p>
        </div>
    )
}

export default Header;