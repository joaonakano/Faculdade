import React, { useState, useEffect } from 'react';
import { db, auth } from './firebaseConnection.js'; // Importando variaveis da conexao do firebase

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
    await deleteDoc(docRef).then(() => {  // O que faz o docRef?
      alert("Post Deletado com Sucesso!");
    }).catch(error => {
      console.log(error);
    });
  }
}