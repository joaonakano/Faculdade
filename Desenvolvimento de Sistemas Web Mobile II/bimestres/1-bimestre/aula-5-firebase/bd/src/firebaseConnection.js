import { initializeApp } from "firebase/app";
import { getFirestore } from "firebase/firestore";
import { getAuth } from "firebase/auth";

const firebaseConfig = {
    apiKey: "AIzaSyAj6HJJ6wwYa-VOog1sr2G1a6wGroM64S8",
    authDomain: "teste-firebase-56a8e.firebaseapp.com",
    projectId: "teste-firebase-56a8e",
    storageBucket: "teste-firebase-56a8e.appspot.com",
    messagingSenderId: "571904145209",
    appId: "1:571904145209:web:c5d50b903325fb6e84dae8"
};
  
const firebaseApp = initializeApp(firebaseConfig);
const db = getFirestore(firebaseApp);
const auth = getAuth(firebaseApp);

export {db, auth};