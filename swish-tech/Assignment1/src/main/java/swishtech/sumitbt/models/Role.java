package swishtech.sumitbt.models;

import java.util.Collection;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

import org.hibernate.annotations.Fetch;
import org.hibernate.annotations.FetchMode;

import com.fasterxml.jackson.annotation.JsonIgnore;

@Entity
@Table(name="roles")
public class Role
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long id;
	
	@NotNull
	@Column(unique=true)
	private String rolename;

	@OneToMany(mappedBy = "role")
    @Fetch(FetchMode.JOIN)
    @JsonIgnore
    private Collection<User> users;
	
	public Role(){}
	
	public Role(String rolename)
	{
		this.rolename=rolename;
	}
	
	public Long getId()
	{
		return id;
	}
	
	public void setId(Long id)
	{
		this.id = id;
	}
	
	public String getRolename()
	{
		return rolename;
	}
	
	public void setRolename(String rolename)
	{
		this.rolename = rolename;
	}

	public Collection<User> getUsers()
	{
		return users;
	}

	public void setUsers(Collection<User> users)
	{
		this.users = users;
	}
	
	
	
}
