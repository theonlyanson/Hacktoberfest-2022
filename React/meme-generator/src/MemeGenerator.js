import React from 'react';

class MemeGenerator extends React.Component {

    constructor() {
        super();
        this.state={
            topText: "",
            bottomText: "",
            randomImg: "https://i.imgflip.com/1bij.jpg",
            allMemeImgs: []
        }
        this.handleChange = this.handleChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
    }

    componentDidMount() {
        fetch("https://api.imgflip.com/get_memes")
            .then(response => response.json())
            .then(response => {
                const {memes} = response.data
                this.setState({allMemeImgs: memes})
            })
    }

    handleChange(event) {
        var {name,value} = event.target;
        this.setState({[name]:value})
    }

    handleSubmit(event) {
        var randNum = Math.floor(Math.random() *60);
        var newState = this.state.allMemeImgs[randNum].url;
        this.setState({randomImg: newState});
        event.preventDefault();
    }

    render() {
        return(
            <div id="formDiv">
                <form onSubmit={this.handleSubmit} id="memeForm">
                    <input
                    type="text"
                    name="topText"
                    value={this.state.topText}
                    onChange={this.handleChange}
                    placeholder="Top Text"
                    className="formClass"
                    />

                    <input
                    type="text"
                    name="bottomText"
                    value={this.state.bottomText}
                    onChange={this.handleChange}
                    placeholder="Bottom Text"
                    className="formClass"
                    />

                    <button id="button" className="formClass">Generate</button>

                </form>

                <div className="memeDisplayDiv">
                    <img src={this.state.randomImg} id="memeImg"/>
                    <h1 id="topText" className="textOut">{this.state.topText}</h1>
                    <h1 id="botText" className="textOut">{this.state.bottomText}</h1>
                </div>
            </div>
        );
    }
}

export default MemeGenerator;