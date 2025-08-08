import Button from './Button';
import './Styles/Header.css';

// Componente com o HEADER da Página, ele recebe os PROPS com as funções básicas de APAGAR o LocalStorage, GERAR novo Conselho e EXIBIR Conselhos Curtidos para serem aplicados nos OnClicks dos componentes de Botões
export default function Header({ handleFullDeletion, handlesShowAdviceListClick, handleNewAdvice, isListVisible }) {
    return(
        <header className="header">
            <div className="menu">
                <Button className="transparent-background menu-button roboto-mono" label="apagar todos" onClick={handleFullDeletion}/>
                <span className="divider transparent-background">|</span>
                <Button className="transparent-background menu-button roboto-mono" label={isListVisible ? "gerador" : "pins"} onClick={handlesShowAdviceListClick}/>
                <Button className="transparent-background menu-button highlight-menu roboto-mono"label="novo conselho" onClick={handleNewAdvice}/>
            </div>
            <h1 className="title">Advice Generator</h1>
        </header>
    )
}