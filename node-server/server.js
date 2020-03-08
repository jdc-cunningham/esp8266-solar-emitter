const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const port = 5000;

// CORs
app.use((req, res, next) => {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
});

app.use(bodyParser.text());

app.use(
    bodyParser.urlencoded({
        extended: true
    })
);

app.post('/esp-emit-solar', (req, res) => {
    console.log(req.body, new Date());
    res.status(200).send('ok');
});

app.listen(port, () => {
    console.log(`App running... on port ${port}`);
});