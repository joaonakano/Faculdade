import React, { useState, useEffect } from 'react';
import "./App.css";

export default function App() {
  const [message, setMessage] = useState("");

  useEffect(() => {
    fetch("http://localhost:8000/message")
    .then(res => res.json())
    .then(data => setMessage(data.message))
    .catch(err => console.error(err));
  }, []);

  return(
    <div className="App">
      <h1>{message}</h1>
    </div>
  );
}