import axios from "axios";

/*  
Send request interface. This is a generalization such that 
every request you send shall pass through this. The generalised 
function takes two generic types. 

T -> Input
O -> Output

If you are watching as a contributer,
Contribute code and document
how would you make this better
*/

interface requestInterface<T, O> {
  url: string;
  method: "GET" | "POST" | "PUT" | "DELETE";
  data?: T;
}

interface ToDoInterface {
  userId: string;
  id: number;
  title: string;
  completed: boolean;
}

async function sendRequest<T, O>({
  url,
  method,
  data,
}: requestInterface<T, O>): Promise<O> {
  async function sendGETRequest(url) {
    const { data } = await axios.get(url);
    return data;
  }

  async function sendPOSTRequest(url, rData) {
    const { data } = await axios.post(url, rData);
    return data;
  }

  async function sendPUTRequest(url, rData) {
    const { data } = await axios.put(url, rData);
    return data;
  }

  async function sendDeleteRequest(url) {
    const { data } = await axios.delete(url);
    return data;
  }

  if (method === "GET") return await sendGETRequest(url);
  if (method === "POST") return await sendPOSTRequest(url, data);
  if (method === "PUT") return await sendPUTRequest(url, data);
  if (method === "DELETE") return await sendDeleteRequest(url);

  throw new Error("Not Implemented");
}

// lets make a request to json placeholder todo
sendRequest<null, ToDoInterface>({
  url: "https://jsonplaceholder.typicode.com/todos/",
  method: "GET",
  data: null,
}).then((data) => {
  console.log(data);
});
