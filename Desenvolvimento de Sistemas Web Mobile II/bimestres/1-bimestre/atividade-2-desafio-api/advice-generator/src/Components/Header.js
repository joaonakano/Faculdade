import Button from './Button';
import './Styles/Header.css';

export default function Header({ handleFullDeletion, handlesShowAdviceListClick, handleNewAdvice }) {
    return(
        <header className="header">
            <div className="menu">
                <Button className="transparent-background menu-button roboto-mono" label="apagar todos" onClick={handleFullDeletion}/>
                <span className="divider transparent-background">|</span>
                <Button className="transparent-background menu-button roboto-mono" label="pins" onClick={handlesShowAdviceListClick}/>
                <Button className="transparent-background menu-button highlight-menu roboto-mono"label="novo conselho" onClick={handleNewAdvice}/>
            </div>
            <h1 className="title">Advice Generator</h1>
        </header>
    )
}