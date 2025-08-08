
import { initializeApp } from 'firebase/app'
import { getAuth } from 'firebase/auth'
import { getFirestore } from 'firebase/firestore'
import { getStorage } from 'firebase/storage';

const firebaseConfig = {
  apiKey: "AIzaSyCo6lLbuqfLtvnsmFuGLg-ZWPm1JojUFXE",
  authDomain: "ticketb-446d2.firebaseapp.com",
  projectId: "ticketb-446d2",
  storageBucket: "ticketb-446d2.appspot.com",
  messagingSenderId: "257009028695",
  appId: "1:257009028695:web:2ddf67adeee59e546b1d12"
};

const firebaseApp = initializeApp(firebaseConfig);

const auth = getAuth(firebaseApp);
const db = getFirestore(firebaseApp);
const storage = getStorage(firebaseApp);

export { auth, db, storage };