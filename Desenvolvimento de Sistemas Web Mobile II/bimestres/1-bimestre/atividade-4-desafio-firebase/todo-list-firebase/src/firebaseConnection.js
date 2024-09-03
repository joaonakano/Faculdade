import { initializeApp } from "firebase/app";
import { getFirestore } from "firebase/firestore";
import { getAuth } from "firebase/auth";

const firebaseConfig = {
    apiKey: "AIzaSyClbAPaYDkJQqmhOzezdSQv5Wzq8bHFy-Q",
    authDomain: "projeto-todolist-8934c.firebaseapp.com",
    projectId: "projeto-todolist-8934c",
    storageBucket: "projeto-todolist-8934c.appspot.com",
    messagingSenderId: "700897034178",
    appId: "1:700897034178:web:0227bef845d951691ae05b"
};

const app = initializeApp(firebaseConfig);
const db = getFirestore(app);
const auth = getAuth(app);

export {db, auth};