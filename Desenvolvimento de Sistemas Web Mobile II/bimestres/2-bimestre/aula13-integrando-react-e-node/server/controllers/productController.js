import firebase from '../firebase.js';
import Product from '../models/productModel.js';

import {
    getFirestore,
    collection,
    doc,
    addDoc,
    getDoc,
    getDocs,
    updateDoc,
    deleteDoc
} from 'firebase/firestore';

const db = getFirestore(firebase);

//Criar um Produto
export const createProduct = async (req, res, next) => {
    try {
        const products = await getDocs(collection(db, 'products'));
        res.status(200).send(products);
    } catch (error) {
        res.status(400).send(error.message);
    }
};

//Ler um Produto específico