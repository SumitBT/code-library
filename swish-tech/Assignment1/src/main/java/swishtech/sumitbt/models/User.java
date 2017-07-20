package swishtech.sumitbt.models;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinTable;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="users")
public class User
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long id;
	
	@NotNull
	@Column(unique=true)
	private String username;
	
	@NotNull
	@Column(unique=true)
	private String email;
	
	@NotNull
	private String password;
	
	@NotNull
	private boolean enabled;
	
	@ManyToOne
    @JoinTable(name="user_role",
               joinColumns={@JoinColumn(name="user_id")},
               inverseJoinColumns={@JoinColumn(name="role_id")})
    private Role role;
	
	public User(){}
	
	public User(String username,String email,String password)
	{
		this.username=username;
		this.email=email;
		this.password=password;
	}
	
	public Long getId()
	{
		return id;
	}
	
	public void setId(Long id)
	{
		this.id = id;
	}
	
	public String getUsername()
	{
		return username;
	}
	
	public void setUsername(String username)
	{
		this.username = username;
	}

	public String getEmail()
	{
		return email;
	}
	
	public void setEmail(String email)
	{
		this.email = email;
	}
	
	public String getPassword()
	{
		return password;
	}
	
	public void setPassword(String password)
	{
		this.password = password;
	}

	public boolean isEnabled()
	{
		return enabled;
	}

	public void setEnabled(boolean enabled)
	{
		this.enabled = enabled;
	}

	public Role getRole()
	{
		return role;
	}

	public void setRole(Role role)
	{
		this.role = role;
	}
	
	
	
}
