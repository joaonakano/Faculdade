const express = require('express');
const cors = require('cors');

import config from './config.js';
import productRoute from './routes/productRoute.js';

const app = express();
const PORT = process.env.PORT || 8000;

app.use(cors());
app.use(express.json());

api.use('/api', productRoute);

app.get('/message', (req, res) => {
    res.json({message: 'Hello from server!'});
});

app.listen(config.port, () => {
    console.log(`Server is live @ ${config.hostUrl}`);
});