import React, { useState, useEffect } from 'react';
import { db, auth } from './firebaseConnection.js';

import {
  doc,
  collection,
  addDoc,
  getDocs,
  updateDoc,
  deleteDoc,
  onSnapshot  
} from 'firebase/firestore';

import {
  createUserWithEmailAndPassword,
  signInWithEmailAndPassword,
  signOut,
  onAuthStateChanged
} from 'firebase/auth';

export default function App() {
  const [tarefa, setTarefa] = useState('');
  const [status, setStatus] = useState('');
  const [idTarefa, setIdTarefa] = useState('');
  const [idAutor, setIdAutor] = useState('');

  const [email, setEmail] = useState('');
  const [senha, setSenha] = useState('');
  
  const [usuario, setUsuario] = useState(false);
  const [detalhesUsuario, setDetalhesUsuario] = useState({});

  const [todoList, setTodoList] = useState([]);

  useEffect(() => {
    async function todoListFetch(){
      const data = onSnapshot(collection(db, "todoList"), snapshot => {
        let listaDeAfazeres = [];
        snapshot.forEach(doc => {
          listaDeAfazeres.push({
            id: doc.id,
            titulo: doc.data().titulo,
            tarefa: doc.data().tarefa,
            status: doc.data().status,
            idAutor: doc.data().idAutor
          });
        });
        setTodoList(listaDeAfazeres);
      });
    }
    todoListFetch();
  }, []);

  useEffect(() => {
    async function verificarLogin() {
      onAuthStateChanged(auth, user => {
        if (user) {
          setUsuario(true);
          setDetalhesUsuario({
            uid: user.uid,
            email: user.email
          });
          setIdAutor(user.uid);
        } else {
          setUsuario(false);
        }
      })
    }
    verificarLogin();
  },[]);

  async function novoUsuario() {
    await createUserWithEmailAndPassword(auth, email, senha)
    .then(() => {
      alert("Usuário cadastrado com sucesso!");
      setEmail("");
      setSenha("");
    })
    .catch(err => {
      if (err.code === 'auth/weak-password') {
        alert("Senha fraca! Utilize uma senha mais segura.");
      }

      if (err.code === 'auth/email-already-in-use') {
        alert("Emaill já cadastrado! Tente novamente com um e-mail diferente ou acesse sua conta.")
      }
    });
  }

  async function logarUsuario() {
    await signInWithEmailAndPassword(auth, email, senha)
    .then(value => {
      alert("Usuário logado com sucesso!");
      setUsuario(true);
      setDetalhesUsuario({
        uid: value.user.uid,
        email: value.user.email
      });
      setEmail("");
      setSenha("");
    })
    .catch(err => {
      if (err.code === 'auth/invalid-email') {
        alert("E-mail invalido! Utilize um e-mail válido.");
      }

      if (err.code === 'auth/invalid-password') {
        alert("Senha incorreta! Insira uma senha válida para este usuário.");
      }
    });
  }

  async function fazerLogout() {
    await signOut(auth);
    setUsuario(false);
    setDetalhesUsuario({});
  }

  // CRUD
  async function adicionarTarefa() {
    await addDoc(collection(db, "todoList"), {
      tarefa: tarefa,
      status: status,
      idAutor: idAutor
    })
    .then(() => {
      alert("Registro realizado com sucesso!");
      setIdAutor("");
      setStatus("");
      setTarefa("");
    })
    .catch(err => {
      console.log(err);
    })
  }

  async function buscarTodoList() {
    const config = collection(db, "todoList");
    await getDocs(config)
    .then(snapshot => {
      let lista = [];
      snapshot.forEach(doc => {
        lista.push({
          id: doc.id,
          titulo: doc.data().titulo,
          tarefa: doc.data().tarefa,
          status: doc.data().status,
          idAutor: doc.data().idAutor
        });
      });
      setTodoList(lista);
      alert("Tarefas recuperadas com sucesso!");
    })
    .catch(err => {
      console.log(err);
    })
  }

  async function editarTarefa() {
    const tarefaEditada = doc(db, "todoList", idTarefa);

    await updateDoc(tarefaEditada, {
      tarefa: tarefa,
      status: status,
      idAutor: idAutor
    })
    .then(() => {
      alert("Tarefa editada com sucesso!");
      setStatus('');
      setTarefa('');
      setIdAutor('');
    })
    .catch(err => {
      console.log(err);
    });
  }

  async function removerTarefa(id) {
    const tarefaDeletada = doc(db, "todoList", id);
    await deleteDoc(tarefaDeletada)
    .then(() => {
      alert("Tarefa removida com sucesso!");
    })
    .catch(err => {
      console.log(err);
    })
  }

  return(
    <div>
      <h1>Todo-List with Firebase</h1>

      {usuario && (
        <div>
          <strong>Seja bem-vindo(a)</strong>
          <br/>
          <span>ID: {detalhesUsuario.uid}</span>
          <br/>
          <span>Email: {detalhesUsuario.email}</span>
          <br/>
          <button onClick={fazerLogout}>Sair</button>
        </div>
      )}
      
      {!usuario && (
        <div>
          <h2>Usuários</h2>
          <label>Email:</label>
          <input
          type="e-mail"
          placeholder="Digite um e-mail"
          value={email}
          onChange={(e) => setEmail(e.target.value)} />
    
          <label>Senha:</label>
          <input
          type="password"
          placeholder="Digite uma senha"
          value={senha}
          onChange={(e) => setSenha(e.target.value)} />
    
          <button onClick={novoUsuario}>Cadastrar</button>
          <button onClick={logarUsuario}>Login</button>
        </div>
      )}

      <hr/>

      <h2>TODO</h2>
      <label>ID da Tarefa:</label>
      <input
      placeholder="ID da tarefa"
      value={idTarefa}
      onChange={e => {setIdTarefa(e.target.value)}} />

      <label>Tarefa:</label>
      <input
      type="text"
      placeholder="tarefa"
      value={tarefa}
      onChange={e => {setTarefa(e.target.value)}}/>

      <label>Status:</label>
      <input
      type="text"
      placeholder="concluida"
      value={status}
      onChange={e => {setStatus(e.target.value)}}/>

      <button onClick={adicionarTarefa}>Inserir</button>
      <button onClick={buscarTodoList}>Buscar</button>
      <button onClick={editarTarefa}>Editar</button>
      
      <ul>
        {todoList.map(item => {
          if(item.idAutor === detalhesUsuario.uid) {
            return(
              <li key={item.id}>
                <strong>Tarefa: {item.tarefa}</strong>
                <span>Status: {item.status}</span>
                <button onClick={() => removerTarefa(item.id)}>Apagar</button>
              </li>
            )
          }
        })}
      </ul>
    </div>
  );

  /*
  const [titulo, setTitulo] = useState(''); FEITO
  const [tarefa, setTarefa] = useState(''); FEITO
  const [status, setStatus] = useState(''); FEITO
  const [idTarefa, setIdTarefa] = useState(''); FEITO
  const [idAutor, setIdAutor] = useState(''); FEITO
  */
}