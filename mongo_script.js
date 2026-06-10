const {MongoClient}=require("mongodb");
async function run() {

    const  client = await MongoClient.connect("mongodb://localhost:27017");
    
    const col = client.db("usermanaged").collection("transactions");

    await col.drop().catch(() => {});

    await col.insertMany(require("./transactions.json"));

    for(let doc of require("./transactions_upsert.json")) {
        await col.updateOne(
            {_id:doc._id},
            {$set:doc},
            {upsert:true}
        );
    }
    console.log("Data inserted successfully!");
    client.close();
}
run();