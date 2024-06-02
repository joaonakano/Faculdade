import { BrowserRouter, Routes, Route } from 'react-router-dom';

import Home from './components/TaskList';
import Sobre from './pages/Sobre';
import Header from './components/Header';

export default function RoutesApp() {
    return (
        <>
            <BrowserRouter>
                <Header />
                <Routes>
                    <Route element={<Home />} path='/' />
                    <Route element={<Sobre />} path='/sobre' />
                </Routes>
            </BrowserRouter>
        </>
    );
}