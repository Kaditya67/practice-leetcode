require('dotenv').config();
const express = require('express');
const mongoose = require('mongoose');

const app = express();
const PORT = process.env.PORT || 5000; // Use a higher port number if needed
console.log(PORT);

// MongoDB connection setup
const MONGODB_URL = process.env.MONGODB_URL;
mongoose.connect(MONGODB_URL);
const connection = mongoose.connection;
connection.on('error', (err) => {
  console.error('MongoDB connection error:', err);
});
connection.once('open', () => {
  console.log('MongoDB connected successfully');
});

// Express middleware
app.use(express.json());

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
