import { Link } from 'react-router-dom';
import './style.css'

function Header(){
    return(
        <header>
            <h2>João Vinicius Yuji Nakano</h2>
            <div>
                <Link to='/'>Home</Link>
                <Link to='/sobre'>Sobre</Link>
                <Link to='/contato'>Contato</Link>
                <Link to='/produto/1'>Produto 1</Link>
            </div>
        </header>
    );
}

export default Header;