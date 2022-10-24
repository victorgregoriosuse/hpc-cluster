# Running Ansible
```
sudo ansible-playbook -i hosts nfs.yml --check
sudo ansible-playbook -i hosts deploy.yml --check
```

# Ansible Roles in deploy.yml

## All Nodes
* **sle_node**: Installs cluster wide packages
* **ntp_client**: Installs and configures NTP client
* **slurm_user**: Adds slurm service account user and group

## Head Node
* **head_node**: Adds HPC cluster user on shared storage and generates SSH key pair
* **slurm_mgr**: Installs Slurm Manager and SlurmDBD, dependent on slurm_user

## Compute Nodes
* **compute_node**: Adds HPC cluster user on compute node
* **slurm_client: Installs SlurmD, dependent on slurm_user

# Ansible Roles in nfs.yml

* **nfs_server**: Installs nfs and configures NFSv3 export for /data
* **nfs_client**: Installs nfs client and mounts /data from nfs server
