# Running Ansible
```
sudo ansible-playbook -i hosts nfs.yml --check
sudo ansible-playbook -i hosts deploy.yml --check
```

# Ansible Roles in deploy.yml

## All Nodes
* sle_node: _Installs cluster wide packages_
* ntp_client: _Installs and configures NTP client_
* slurm_user: _Adds slurm service account user and group_

## Head Node
* head_node: _Adds HPC cluster user on shared storage and generates SSH key pair_
* slurm_mgr: _Installs Slurm Manager and SlurmDBD, dependent on slurm_user_

## Compute Nodes
* compute_node: _Adds HPC cluster user on compute node_
* slurm_client: _Installs SlurmD, dependent on slurm_user_

# Ansible Roles in nfs.yml

* nfs_server: _Installs nfs and configures NFSv3 export for /data_
* nfs_client: _Installs nfs client and mounts /data from nfs server_
