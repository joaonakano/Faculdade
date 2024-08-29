import React, { useState, useEffect } from 'react';
import { db, auth } from './firebaseConnection.js'; // Importando variaveis da conexao do firebase
import "./style.css";

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

export default function App(){
  const [titulo, setTitulo] = useState('');
  const [autor, setAutor] = useState('');
  const [idPost, setIdPost] = useState('');
  
  const [email, setEmail] = useState('');
  const [senha, setSenha] = useState('');

  const [usuario, setUsuario] = useState(false);
  const [detalhesUsuario, setDetalhesUsuario] = useState({});

  const [post, setPost] = useState([]);

  useEffect(() => {
    async function carregarPost(){
      const dados = onSnapshot(collection(db, "posts"), (snapshot) => { // O que faz o onSnapshot e quais parametros ele recebe?
        let listaPost = [];
        snapshot.forEach((doc) => {
          listaPost.push({
            id: doc.id,
            titulo: doc.data().titulo,
            autor: doc.data().autor   // .data() para converter em um objeto se estiver formatado de outra forma
          });
        });

      setPost(listaPost);
      });  // collection() pega uma colecao existente com a fonte dos dados e o nome da colecao a ser criada
    }
    carregarPost();
  }, []);

  useEffect(() => {
    async function verificarLogin() {
      onAuthStateChanged(auth, user => {
        if (user) {
          // tem usuario logado
          setUsuario(true);
          setDetalhesUsuario({
            uid: user.uid,
            email: user.email
          });
        } else {
          // não possui usuario logado
          setUsuario(false);
          setDetalhesUsuario({});
        }
      })
    }
    verificarLogin();
  }, []);

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
        alert("Email já cadastrado! Tente novamente com um e-mail diferente ou acesse sua conta.");
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
        email: value.user.email     // Por que nao usamos user.email apenas?
      });
      setEmail("");
      setSenha("");
    })
    .catch(err => {
      if (err.code === 'auth/invalid-email') {}
        alert("E-mail invalido! Utilize um e-mail válido");

      if (err.code === 'auth/invalid-password') {
        alert("Senha incorreta! Insira uma senha válida para este usuário");
      }
    });
  }

  async function fazerLogout() {
    await signOut(auth);
    setUsuario(false);
    setDetalhesUsuario({});
  }

  // (C)reate
  async function adicionarPosts() {
    await addDoc(collection(db, "posts"), {
      titulo: titulo,
      autor: autor
    }).then(() => {
      alert("Cadastro Realizado com Sucesso!");
      setAutor('');
      setTitulo('');
    }).catch((error) => {
      console.log(error);
    }); // await define a execução após todas as funções anteriores serem executadas
  }

  // (R)ead
  async function buscarPosts() {
    const config = collection(db, "posts");
    await getDocs(config).then((snapshot) => {
      let lista = []
      snapshot.forEach((doc) => {
        lista.push({
            id: doc.id,
            titulo: doc.data().titulo,
            autor: doc.data().autor
        });
      });
      setPost(lista);
      alert("Posts Recuperados com Sucesso!");
    }).catch(error => {
      console.log(error);
    })
  }

  // (U)pdate
  async function editarPost() {
    const postEditado = doc(db, "post", idPost);  // O que é o idPost? R: É o state criado no inicio do codigo

    await updateDoc(postEditado, {
      titulo: titulo,
      autor: autor
    }).then(() => {
      alert("Post Editado com Sucesso!");
      setTitulo('');
      setAutor('');
    }).catch(error => {
      console.log(error);
    });
  }

  // (D)elete
  async function excluirPost(id) {
    const postDeletado = doc(db, "posts", id);
    await deleteDoc(postDeletado).then(() => {  // O que faz o docRef?
      alert("Post Deletado com Sucesso!");
    }).catch(error => {
      console.log(error);
    });
  }

  return(
    <div>
      <h1>ReactJS + Firebase</h1>
      
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

      <h2>POSTS</h2>
      <label>ID do Post:</label>
      <input
      placeholder="ID do post"
      value={idPost}
      onChange={e => {setIdPost(e.target.value)}} />
      
      <label>Título:</label>
      <textarea
      type="text"
      placeholder="Título"
      value={titulo}
      onChange={(e) => {setTitulo(e.target.value)}}/>
      
      <label>Autor:</label>
      <input
      type="text"
      placeholder="autor"
      value={autor}
      onChange={e => {setAutor(e.target.value)}}/>

      <button onClick={adicionarPosts}>Inserir</button>
      <button onClick={buscarPosts}>Buscar</button>
      <button onClick={editarPost}>Editar</button>
      
      <ul>
        {post.map(item => (
          <li key={item.id}>
            <strong>ID: {item.id}</strong>
            <span className='title'>Título: {item.titulo}</span>
            <span className='author'>Autor: {item.autor}</span>
            <button onClick={() => excluirPost(item.id)}>Apagar</button>
          </li>
        ))}
      </ul>
    </div>
  );
}