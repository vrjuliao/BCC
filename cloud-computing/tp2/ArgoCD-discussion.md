# Assignment 2

Vinicius Julião Ramos - 2018054630

## Performed Tests:
In order do validate the functionalities of ArgoCD and Kubernetes, I've done two experiments that check the behavior of those applications. The first was that one requested in the scope of this assignment: After changing the version of my model, I built a new docker image and pushed it to docker.io (`docker.io/vrjuliao/american-predictor`), also, I pushed the changed code to the integrated github repository: [https://github.com/vrjuliao/cloud-computing-assignment2](https://github.com/vrjuliao/cloud-computing-assignment2).

Using my client program, I estimated how many time it takes until see the new tagged version in the server responses. Since I pushed the docker image, till notice the version changing in the server responses, it took `6 minutes and 48 seconds`, not being possible to observe that the server got down.

The second test I did, was related to the consistency of the automatic deployment. I forced the container version (at `deployment.yaml`) to be an inexistent version. So, it was expected either the server would go down or the server would keep as the latests existent version. I was observing the behavior for `20 minutes` (since it took less than `7 minutes` to persist changes in the server in the first experiments) and the server kept up using the tag `v0.0.3` that is the latest one.

Both of the two scenarios above are easy to understand if we think that a pod is separately created for the newer version of that deployment. So, the Kubernetes control plane only redirects the traffic for those new pods after checking that they are working. Thus, it is not possible to observe a kind of server restart up, since the new server is up before the traffic redirection.