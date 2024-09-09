import './index.css';

export default function Welcome({ handleLogout }) {
    return(
        <div className="welcome-container">
          <div className="logout-area">
            <button className="transparent-background logout-button" onClick={handleLogout}>Sair</button>
          </div>
        </div>
    );
}