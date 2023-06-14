const MongoClient = require('mongodb').MongoClient;
// creating user with password to mongodb is recommended

const connection_str = 'mongodb://localhost:27017/';
const client = new MongoClient(connection_str);
const dbName = 'echo'

var db = null;

try {
    db = client.db(dbName);
}
catch (e) {
    console.error("database connection failed. " + e)
}

async function cleanup() {
    await client.disconnect();
}

module.exports = { db, cleanup };