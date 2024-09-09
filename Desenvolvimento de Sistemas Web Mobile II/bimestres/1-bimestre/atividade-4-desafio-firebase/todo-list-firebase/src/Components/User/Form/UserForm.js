import './index.css'

export default function UserForm({ stateEmail, setEmail, stateSenha, setSenha, handleRegister, handleLogin }) {
    return(
        <div className='container'>
          <div className='login-form'>
            <h2 className='transparent-background'>Usuários</h2>
            <div className='transparent-background email'>
              <label className='transparent-background'>Email:</label>
              <input
              type="e-mail"
              placeholder="digite um e-mail"
              value={stateEmail}
              onChange={(e) => setEmail(e.target.value)} />
            </div>

            <div className="transparent-background senha">
            <label className='transparent-background'>Senha:</label>
            <input
            type="password"
            placeholder="digite uma senha"
            value={stateSenha}
            onChange={(e) => setSenha(e.target.value)} />
            </div>
            
            <div className="user-form-buttons transparent-background">
              <button className="user-form-button"onClick={handleRegister}>Cadastrar</button>
              <button className="user-form-button" onClick={handleLogin}>Login</button>
            </div>
          </div>
        </div>
    );
}