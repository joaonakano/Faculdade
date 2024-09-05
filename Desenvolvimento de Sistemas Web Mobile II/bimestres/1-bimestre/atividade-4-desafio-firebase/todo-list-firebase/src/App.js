import React, { useState, useEffect } from 'react';
import { db, auth } from './firebaseConnection.js';

import {
  doc,
  setDoc,
  collection,
  addDoc,
  getDoc,
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
  const [titulo, setTitulo] = useState('');
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
      alert("Usuário cadasrado com sucesso!");
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
      titulo: titulo,
      tarefa: tarefa,
      status: status,
      idAutor: idAutor
    })
    .then(() => {
      alert("Registro realizado com sucesso!");
      setIdAutor("");
      setStatus("");
      setTarefa("");
      setTitulo("");
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

    await updateDoc(postEditado, {
      titulo: titulo,
      tarefa: tarefa,
      status: status,
      idAutor: idAutor
    })
    .then(() => {
      alert("Tarefa editada com sucesso!");
      setTitulo('');
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

}