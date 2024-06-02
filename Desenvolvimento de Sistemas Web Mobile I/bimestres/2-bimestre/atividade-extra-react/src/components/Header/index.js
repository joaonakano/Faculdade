import { Link } from "react-router-dom";
import './custom.scss'

export default function Header() {
    return(
        <header>
            <Link to="/">Home</Link>
            <Link to="/sobre">Sobre</Link>
        </header>
    );
}