import React from 'react';
import { BrowserRouter as Router, Routes, Route, Link } from 'react-router-dom';

import Home from './components/Home';
import Artista from './components/Artista';

export default function MyApp(){
  return(
    <Router>
      <div>
        <nav>
          <ul>
            <li><Link to='/'>Home</Link></li>
            <li><Link to='/artista'>Artista</Link></li>
          </ul>
        </nav>
        <Routes>
          <Route path="/artista" element={<Artista />}/>
          <Route path="/" element={<Home />} />
        </Routes>
      </div>
    </Router>
  );
}