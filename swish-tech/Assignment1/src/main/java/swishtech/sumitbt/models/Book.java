package swishtech.sumitbt.models;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="books")
public class Book
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long id;
	
	@NotNull
	@Column(unique=true)
	private String bookname;
	
	@NotNull
	private String authorname;
	
	public Book(){}
	
	public Book(String bookname,String authorname)
	{
		this.bookname=bookname;
		this.authorname=authorname;
	}

	public long getId()
	{
		return id;
	}

	public void setId(long id)
	{
		this.id = id;
	}

	public String getBookname()
	{
		return bookname;
	}

	public void setBookname(String bookname)
	{
		this.bookname = bookname;
	}

	public String getAuthorname()
	{
		return authorname;
	}

	public void setAuthorname(String authorname)
	{
		this.authorname = authorname;
	}
		
}